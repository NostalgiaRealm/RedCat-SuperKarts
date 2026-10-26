# Original game: recovered inspection source

This folder contains a reproducible decompilation of **all five executable modules shipped as the RedCat SuperKarts game runtime**. Start with a module's `full_decompilation.c`, or search its `functions/` directory for one address. Each function has its own matching assembly file.

The original authored source files were not shipped with the game. These files are **Ghidra-generated C-like pseudocode**, recovered from the original binaries. They are useful for comparing the port with the original instructions, but are not the original developers' source code and cannot be compiled into the game. Names, types, parameters, control flow and function boundaries can be inferred incorrectly. The export deliberately preserves warnings and unresolved regions.

## Start reading

| Original module | Responsibility | Recovered code |
| --- | --- | --- |
| `RCSK.exe` | Launcher and process orchestration | [Combined source](modules/RCSK.exe/full_decompilation.c) · [function index](modules/RCSK.exe/functions.tsv) |
| `rcskmenu.dat` | Delphi menus, profiles, options and Adventure flow | [Combined source](modules/rcskmenu.dat/full_decompilation.c) · [function index](modules/rcskmenu.dat/functions.tsv) |
| `rcskspel.dat` | Racing, simulation, sound, input and rendering | [Combined source](modules/rcskspel.dat/full_decompilation.c) · [function index](modules/rcskspel.dat/functions.tsv) |
| `RCMovie.dat` | Original movie player | [Combined source](modules/RCMovie.dat/full_decompilation.c) · [function index](modules/RCMovie.dat/functions.tsv) |
| `SMACKW32.DLL` | Shipped Smacker movie codec | [Combined source](modules/SMACKW32.DLL/full_decompilation.c) · [function index](modules/SMACKW32.DLL/functions.tsv) |

Addresses are native image addresses, such as `00479074`. Most function names were stripped from the binaries; `FUN_00479074` means a function identified at that address. Where the menu's Delphi published-method tables contain an actual class/method name, that metadata is recovered and byte-checked. For example, [TfrmAdventBrief.FormShow](modules/rcskmenu.dat/functions/00479074_TfrmAdventBrief_FormShow.c) is accompanied by [its assembly](modules/rcskmenu.dat/assembly/00479074.asm).

The port's original behavior investigations are in [docs/original-behavior.md](../docs/original-behavior.md). Original data extraction and conversion are implemented in [tools/prepare-assets.py](../tools/prepare-assets.py); the browser assets are in [public/assets](../public/assets/). Those derived assets and this recovered code serve different purposes.

## What is included

For each module:

- `full_decompilation.c` and `functions/*.c`: every identified non-external function, with native addresses, signatures, body ranges and decompiler warnings.
- `functions.tsv`: the complete index, including decompilation status, no-return assumptions, thunk status and the path to each source file.
- `assembly/*.asm` and `assembly.tsv`: original instruction bytes and addresses, including instructions that analysis could not assign to a function.
- `calls.tsv`, `references.tsv`, `symbols.tsv`, `imports.tsv`, `exports.tsv`: call sites, data/code references and recovered names. Computed/unresolved calls remain marked as such.
- `data.tsv`, `strings.tsv`, `memory.tsv`: defined static data, strings and mapped sections.
- `pcode_origins.tsv`: the native instruction origins used by the decompiler.
- `function-recovery.tsv`: why additional function starts were considered. Published-method names and direct calls have stronger evidence than aligned-block or data-pointer heuristic seeds.
- `instructions_outside_functions.tsv` and `executable_without_instructions.tsv`: explicit coverage gaps. Executable sections also contain embedded strings, tables and padding; these sizes are **not a count of missing source code**.
- `summary.json` and `decompiler-warnings.json`: counts and the functions whose pseudocode needs additional scrutiny.

The top-level [input manifest](input-manifest.json) identifies exact input bytes and CD/installed-copy comparisons. `inputs/` contains byte-identical local copies, so the original installation and CD directory are never modified. The manifest inventories all 105 DOS/PE images on the CD; 100 installer, autorun, driver and other support redistributables are excluded from this game-runtime decompilation. Windows system DLLs are external dependencies, not recovered game source.

[reference-data.json](reference-data.json) hashes the 777 non-PE game data/media files from the CD and points to the existing extraction tools and resource evidence. It includes original configuration, archives, help, images, sounds and movies. Those assets are needed to interpret constants and resource references in the recovered code; they are not source code themselves.

## Completeness and limits

[verification.json](verification.json) is the authoritative final result. The verifier checks that every indexed function has separate and combined source, that every function has an assembly file, and that every exported instruction byte matches the original PE file. All five original CD and installed-module hashes are checked again after analysis. [SHA256SUMS.txt](SHA256SUMS.txt) covers the distributable files in this folder; private Ghidra databases under ignored `work/` are excluded.

“Every identified function exported” does not mean “all original semantics recovered.” In particular:

- Compiler-generated exception handling and no-return assumptions can make a function appear to end early. Follow its assembly and callers when a C listing seems too short.
- Indirect calls, vtables and packed data can defeat automatic discovery. Unassigned instructions and undecoded executable ranges remain listed rather than being presented as proven functions.
- Decompiled register/stack variables and argument lists may be wrong even when the instruction translation succeeds.
- A warning-free export does not prove that the port behaves identically. Behavior fixes require separate evidence and focused validation.

This is a static inspection deliverable. No original executable was run, and no desktop game build was created for it.

## Reproduce or verify

Requirements: Python 3 with `pefile`, Java and Ghidra 12.1.4 (`ghidra-headless` on `PATH`). The original CD and installed-copy defaults in the script refer to this workstation; use the arguments below when they are elsewhere.

From the repository root, a fresh import and export is:

```bash
python3 original-source/tools/export.py \
  --cd-root "/path/to/RedCat Superkarts CD" \
  --installed-root "/path/to/installed/game/data" \
  --ghidra "/path/to/ghidra/support/analyzeHeadless"
python3 original-source/tools/verify.py
```

If the earlier repository analysis databases still exist, `--reuse-existing` reuses **copied** databases only after checking their recorded input SHA-256. This is how the four previously analyzed application modules were exported for this delivery; the codec received a fresh import. Existing source and command hashes remain in `logs/`. The installed copy is an optional comparison; the CD supplies the actual inputs.

The recovery pass adds byte-validated Delphi method targets, direct call targets, decoded frame prologues, plausible data-referenced code entries and aligned decoded blocks following closed control flow. It does not indiscriminately turn all executable bytes into instructions. Initial automatic analysis finishes before recovery and export, so later background analysis cannot silently add unexported functions. Each failed decompilation is retried with a longer timeout and, if still unsuccessful, receives an assembly fallback instead of a fabricated C body.

To validate an existing export without running Ghidra:

```bash
python3 original-source/tools/verify.py
```

The verifier uses the included binary copies. If original external paths are still available, it checks those as well. Regenerating an export replaces only that module's generated output and private copied database; it never writes to the original game directory.
