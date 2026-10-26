# Release publication policy

Publish each requested release to both
[GitHub](https://github.com/NostalgiaRealm/RedCat-SuperKarts/releases) and
[GitLab](https://gitlab.com/Nostalgia_Realm/RedCat-SuperKarts/-/releases), using the
same version tag, frozen source commit, changelog and downloadable artifacts.
`package.json` is the version authority; its version hook regenerates the menu
version and local runtime bundles before the release source is frozen.

## Always include the original-code reference

Starting with 1.0.0, **every release update must publish the entire
`original-source/` directory on both hosts**. Include it in the committed source,
the complete release source archive, and the dedicated original-source archive.
Do not omit hidden files, ignored files, copied inputs, working databases,
helper files or any other subfolder inside it. This is an explicit project
requirement, including when later changes only affect the JavaScript port.

The folder is recovered C-like pseudocode, assembly and supporting evidence,
not the original developers' authored source project. Preserve its provenance,
warnings and coverage limits. It is a reference for comparison, not a runtime
dependency; desktop game payloads do not need to contain it.

## Release contents

- Source at the release tag, including editable `source/`, generated `src/`,
  prepared `public/assets/`, the complete `original-source/`, tools and docs.
- `RedCat-SuperKarts-<version>-source.tar.gz`, created from the frozen source
  commit, so local play does not require the original disc or a media import.
- `RedCat-SuperKarts-<version>-original-source.tar.gz`, containing the complete
  reference directory for separate download.
- Requested desktop builds for Linux x64, Windows x64, macOS Intel and macOS
  Apple Silicon, with architecture identified in each filename.
- The version's changelog, build metadata and downloadable-file checksums.

After committing the complete source, create both 1.0.0 source archives:

```sh
npm run release:source -- --output release/1.0.0
```

Use the matching directory for a later version. The helper does not run tests
or inspect archive contents. Freeze source and version before producing release
artifacts; do not move an already published version tag to accommodate later
changes.

Describe the checks actually performed, including any explicit exclusions.
Successful compilation, packaging, publication and checksum generation are
separate from gameplay validation. Prior evidence must retain its original
source and platform scope.

For 1.0.0, the user's instruction is to run **no tests or build checks**. Use
`RCSK_SKIP_BUILD_CHECKS=1` while packaging and `skip_build_checks: true` for the
macOS release workflow. Do not run release launch checks, payload verification,
metadata assertions or archive-content checks. This release-specific exclusion
does not remove the development checks or change their historical records.

## Release notes

- [1.0.0 — current desktop and source release](1.0.0.md)
- [0.9.0 — desktop and source release](v0.9.0.md)
- [0.1.0 — source release](v0.1.0.md)
