# Original track surface and collision rules

The recovered active kart code does **not** assign friction, water, mud, or oil
behavior from texture names, texture IDs, or pixels. The implementation must
preserve the independent sources of geometry, contacts, vehicle parameters,
bonus hits, and markers. A painted patch is not itself a new physics rule.
This conclusion covers the recovered active player and NPC paths below, rather
than claiming every unused engine branch has been interpreted.

## Ground geometry

`0x494d20` loads each RMP sector in four groups: road, land, extra, rail.
`0x49cc90` reads each quad's four XYZ/UV/color vertices and six triangle indices;
there is no surface coefficient or material identifier in a quad record.
`0x494f40` builds triangle normals and plane constants from those vertices.
The four group positions also select the four configured rendering textures.
The road vertex copier `0x4968a0`, for example, adjusts UVs using texture atlas
metadata, while retaining the same XYZ coordinates.

`0x495fe0` tests road first, then land, then extra, retaining original triangle
order. The first triangle containing the point in XZ whose normal Y is strictly
greater than float32(0.4) wins. The test deliberately ignores the query's Y.
`0x496290` returns the selected plane height. With no eligible triangle, it
returns the sector's fallback plane height. It does not select the nearest
surface vertically or pick a texture-specific response.

The RMP **rail rendering group is not part of this ground search**. Horizontal
rail collision comes from the separate CMP barriers and the PMP sector lists.
Registered scenery objects and kart bodies are another collision source.
Consequently the presence or transparency of a texture is insufficient to
decide whether the corresponding visible feature blocks a kart.

`0x416650` samples current and predicted wheel positions through
`0x4977d0` → `0x495fe0` → `0x496290`, using original wheel offsets and mesh radii.
It handles contact, vertical motion and body orientation using sampled heights.
It does not read the selected triangle's texture.

## Tyres and movement

The active player force callback `0x415990` selects the original low-speed or
lateral tyre path and calls drive/resistance/gearing helpers. In `0x415160`,
front/rear tyre parameters come from Phys0/1/2 records indexed by selected car
and tyre upgrade. In `0x415520`, rolling resistance, air resistance and slope
terms use the vehicle record, tyre upgrade, velocity, orientation and handbrake.
Neither path takes a world texture, road/land group, or terrain coefficient.

NPC movement `0x401200` calls longitudinal `0x414470` and lateral `0x414750`.
Their inputs are the original difficulty-specific Cars records, controls,
velocity, active status and the original shared player tyre/slip globals.
Road graph selection is separate. A land triangle does not receive a newly
invented grass slowdown in either player or NPC movement.

Oil and gum are actual bonus hit types, dispatched by `0x455b00` and the
recipient's effect handlers. For example NPC oil enters `0x411e50`; the port's
bonus effects retain that path. A road texture that looks oily is not an oil
pickup or an oil hit.

## Shipped course inventory

Regenerate the complete machine-readable inventory with:

```sh
node tools/audit-track-surfaces.mjs
```

The output `evidence/gameplay/track-surfaces.json` includes original source
hashes, converted track hashes, every rendering texture, triangle totals,
eligible upward triangles, CMP counts, and both PMP trigger-slot counts.
It also inventories the separate DMP drive-node marker counts.

| Course | Road texture / triangles | Land texture / triangles | Extra texture / triangles | Rail texture / triangles | CMP barriers |
| --- | --- | --- | --- | --- | --- |
| Netherlands | ned01 / 2066 | ned00 / 5894 | ned03 / 400 | ned02 / 652 | 680 |
| Germany | duits01 / 2420 | duits00 / 5702 | duits03 / 804 | duits02 / 2162 | 680 |
| England | eng01 / 2432 | eng00 / 5180 | eng03 / 806 | eng02 / 854 | 665 |
| France | fran01 / 3108 | fran00 / 5532 | fran03 / 314 | fran02 / 1800 | 661 |
| Spain | span01 / 2866 | span00 / 5748 | span03 / 492 | span02 / 1748 | 630 |
| Italy | ital01 / 2930 | ital00 / 5362 | ital03 / 460 | ital02 / 1644 | 656 |

The editor names include ToggleConcreteRoad (7), Water (67), Particle Water
(68), ICE_ON (77), and ICE_OFF (78). **None occurs in either PMP trigger slot
on any of the six shipped courses.** Their names alone are not evidence of an
active surface effect.

The separate DMP graph does contain eleven Particle Water markers68 in the
Netherlands, and grass marker1 in Netherlands/England. It contains no
ToggleConcreteRoad7, Water67, ICE_ON77, ICE_OFF78, or zipper53 on any course.
Thus the absence statement above applies specifically to PMP; it must not
be extended to every drive-node particle marker.
The active NPC callback `0x40b0b0` explicitly checks current DMP marker68
or the racer's slippery flag and multiplies all three linear velocities by
float32(.98) once per original callback. The port retains this authored-marker
rule in `NativeAIDriver`; it is independent of the rendering texture.

Rain waypoint markers 79/80 occur in Netherlands and England; England also
uses rain-data marker83. Germany uses global snow markers86/87. The recovered
79/80 wrappers `0x442140/0x442180` change the weather object's byte at+0xa8;
83 uses `0x4421e0` and weather configuration. They do not change tyre tables
or apply a launch force. Those weather behaviors belong to their original
object controllers, independently of ground texture.

## Validation scope

The existing track tests compare 960 sector/triangle samples with original
x86 instructions on all six shipped courses, plus original starting poses.
The additional texture-invariance regression replaces every rendering texture
name and group texture index while retaining geometry, then verifies the same
ground selections. It guards the port's separation of rendering and physics;
it is not a new full-process Windows comparison. The native force, wheel,
rail and scenery fixtures validate their own separate paths.
