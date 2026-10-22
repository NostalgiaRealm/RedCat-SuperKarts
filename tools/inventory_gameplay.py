#!/usr/bin/env python3
"""Read SuperKarts gameplay inputs without modifying the installation.

Keeps authored records and their source line numbers alongside a conservative
inventory. A configured value is not proof that a native code path uses it.
"""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT = Path("/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data")


def read_ini(path):
    data = path.read_bytes()
    sections = {}
    section = ""
    for number, line in enumerate(data.decode("cp1252", errors="replace").splitlines(), 1):
        stripped = line.strip()
        if not stripped or stripped.startswith((";", "//")):
            continue
        match = re.match(r"\[([^]]+)]", stripped)
        if match:
            section = match[1].casefold()
            sections.setdefault(section, {})
        elif "=" in stripped:
            key, value = stripped.split("=", 1)
            # Semicolons inside KEYS are separators, not comments.
            if key.strip().casefold() != "keys":
                value = value.split(";", 1)[0]
            sections.setdefault(section, {})[key.strip().casefold()] = {
                "value": value.strip(), "line": number
            }
    return {"source": path.name, "sha256": hashlib.sha256(data).hexdigest(),
            "bytes": len(data), "sections": sections}


def get_values(document, section):
    return {key: entry["value"] for key, entry in document["sections"][section.casefold()].items()}


def number_rows(document, section):
    return [(int(key), entry["value"]) for key, entry in document["sections"][section.casefold()].items()
            if key.isdigit()]


def binary_table(path, record_floats):
    data = path.read_bytes()
    stride = record_floats * 4
    if len(data) % stride:
        raise ValueError(f"{path}: size not divisible by candidate stride")
    return {
        "source": path.name, "sha256": hashlib.sha256(data).hexdigest(), "bytes": len(data),
        "interpretation": "native 0x4319f0 verifies 20 records and stride; named fields separately recovered from native tweak menus",
        "loader": "rcskspel.dat 0x4319f0",
        "recordBytes": stride, "recordCount": len(data) // stride,
        "records": [
            {"index": index, "offset": index * stride,
             "floats": list(struct.unpack_from(f"<{record_floats}f", data, index * stride)),
             "uint32": list(struct.unpack_from(f"<{record_floats}I", data, index * stride))}
            for index in range(len(data) // stride)
        ],
    }


def inventory(source, output):
    output.mkdir(parents=True, exist_ok=True)
    names = ["game.ini", "gameplay.ini", "race.ini", "track.ini", "npc_ai.ini",
             "garage.ini", "car_ssr.ini", "language.ini", "overlay.ini", "gen_anim.ini",
             "CharAnim.ini", "ini/settings.ini", "ini/shellang.ini", "ini/trans.dat",
             "ini/brief.dat", "Etappe0.ini", *[f"etappe{i}.ini" for i in range(1, 6)]]
    documents = {name: read_ini(source / name) for name in names}
    # Relative source paths distinguish the active root settings from old ini copies.
    for name, document in documents.items():
        document["source"] = name
    tracks = []
    for index, raw in number_rows(documents["track.ini"], "maps"):
        fields = [field.strip() for field in raw.split(",")]
        tracks.append({"id": index, "name": fields[8], "map": fields[1],
                       "textureNames": fields[2:6], "skyNames": fields[6:8],
                       "musicIndex": int(fields[9]), "timerValue": int(fields[10]),
                       "ambientRGB": list(map(int, fields[11:14])),
                       "mirrorFlag": int(fields[14]),
                       "evidence": f"track.ini [MAPS] {index}"})
    characters = []
    for index, raw in number_rows(documents["game.ini"], "available_characters"):
        name, mesh, ai, color = raw.split(",")
        characters.append({"id": index, "name": name, "mesh": mesh, "ai": int(ai),
                           "color": int(color), "playerSelectable": index < 4,
                           "selectableEvidence": "ini/shellang.ini character controls and ini/settings.ini [WINMOVIES]; native menu verification pending"})
    result = {
        "format": "superkarts-gameplay-inventory-v1",
        "sourceRoot": str(source),
        "status": "Authored inputs confirmed; runtime applicability separately unresolved.",
        "engineEvidence": {
            "source": "car_ssr.ini header", "nameInSource": "M25 engine",
            "spookkasteelCompatibility": "No Davi-Script objects or Genesis3D assets found in this bounded inventory. Do not reuse platformer physics."
        },
        "tracks": tracks,
        "characters": characters,
        "difficulty": [{"id": i, "name": name, "evidence": f"ini/shellang.ini [DUTCH] {i+8}"}
                       for i, name in enumerate(["Makkelijk", "Normaal", "Moeilijk"])],
        "raceTypes": [
            {"id": 0, "name": "NormalRace", "label": "Landenrace", "availability": "QuickRace and adventure"},
            {"id": 1, "name": "TimeTrial", "label": "Tijdrace", "availability": "QuickRace and adventure"},
            {"id": 2, "name": "ItemRace", "label": "Sterrenrace", "availability": "QuickRace and adventure"},
            {"id": 3, "name": "DuelRace", "label": "Duelrace", "availability": "Adventure briefing"},
            {"id": 4, "name": "BonusRace", "label": None, "availability": "Enum only; selectable/reachable status unresolved"},
        ],
        "bonusParameters": {key: float(value) for key, value in get_values(documents["game.ini"], "bonus_data").items()},
        "objectTypes": dict(number_rows(documents["Etappe0.ini"], "objecttypes")),
        "triggerTypes": dict(number_rows(documents["Etappe0.ini"], "triggers")),
        "pathTypes": dict(number_rows(documents["Etappe0.ini"], "pathtypes")),
        "ai": get_values(documents["npc_ai.ini"], "rcr_global"),
        "controls": get_values(documents["game.ini"], "input"),
        "vehicles": dict(number_rows(documents["car_ssr.ini"], "cars")),
        "configuration": documents,
        "binaryTables": [
            binary_table(source / f"Phys{i}.dat", 43) for i in range(3)
        ] + [binary_table(source / f"cars{i}.dat", 31) for i in range(4)],
        "unresolved": [
            "Native integration step and relationship to render cap.",
            "Complete kart integration and collision response; isolated steering/force kernels now recovered and instruction-tested.",
            "Remaining binary table fields and applicability of unused records; native selects Phys/cars by difficulty.",
            "Native lap validation, countdown, finish ordering and time gate selection.",
            "AI path following, overtaking, catchup and bonus choice implementation.",
            "Which legacy object/trigger/vehicle IDs occur in the shipped tracks.",
            "Native bonus pickup eligibility, stacking, duration start/end boundaries and effect implementation.",
            "Adventure sequence, unlock conditions, save serialization and highscore ranking.",
        ],
    }
    (output / "inventory.json").write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n")
    print(f"Inventoried {len(tracks)} tracks, {len(characters)} characters, "
          f"{len(documents)} configuration files and {len(result['binaryTables'])} binary tables.")
    return result


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=DEFAULT)
    parser.add_argument("--output", type=Path, default=ROOT / "evidence" / "gameplay")
    options = parser.parse_args()
    inventory(options.source, options.output)
