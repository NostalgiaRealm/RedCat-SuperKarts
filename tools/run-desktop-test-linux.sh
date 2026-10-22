#!/usr/bin/env bash
# Run the Electron integration test in an isolated X11 desktop. An actual
# window manager is required for native fullscreen and focus transitions.
set -euo pipefail
rcsk_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
cd -- "$rcsk_root"
rcsk_variant=source
if [[ -n "${RCSK_DESKTOP_EXECUTABLE:-}" ]]; then rcsk_variant=packaged; fi
rcsk_evidence="$rcsk_root/evidence/desktop/$rcsk_variant"
mkdir -p -- "$rcsk_evidence"

if [[ "${RCSK_DESKTOP_TEST_DISPLAY_READY:-}" != 1 ]]; then
  for rcsk_tool in xvfb-run dbus-run-session wmctrl; do
    command -v "$rcsk_tool" >/dev/null || { echo "Desktop test requires $rcsk_tool." >&2; exit 1; }
  done
  exec xvfb-run -a -s '-screen 0 1280x1024x24' dbus-run-session -- \
    env RCSK_DESKTOP_TEST_DISPLAY_READY=1 bash "$0" "$@" \
    2>"$rcsk_evidence/headless-session.log"
fi

if command -v openbox >/dev/null; then
  rcsk_wm=(openbox --sm-disable)
elif command -v fluxbox >/dev/null; then
  rcsk_wm=(fluxbox)
elif command -v kwin_x11 >/dev/null; then
  rcsk_wm=(kwin_x11 --replace)
else
  echo 'Desktop test requires an installed X11 window manager: openbox, fluxbox, or kwin_x11.' >&2
  exit 1
fi
QT_QPA_PLATFORM=xcb KWIN_COMPOSE=N "${rcsk_wm[@]}" >"$rcsk_evidence/window-manager.log" 2>&1 &
rcsk_wm_pid=$!
trap 'kill "$rcsk_wm_pid" 2>/dev/null || true; wait "$rcsk_wm_pid" 2>/dev/null || true' EXIT
rcsk_wm_ready=0
for ((rcsk_attempt=0; rcsk_attempt<100; rcsk_attempt++)); do
  if wmctrl -m >"$rcsk_evidence/window-manager-state.txt" 2>/dev/null; then rcsk_wm_ready=1; break; fi
  kill -0 "$rcsk_wm_pid" 2>/dev/null || break
  sleep .1
done
if [[ "$rcsk_wm_ready" != 1 ]]; then
  echo "X11 window manager failed to become ready; see $rcsk_evidence/window-manager.log." >&2
  exit 1
fi
export RCSK_DESKTOP_WINDOW_MANAGER="${rcsk_wm[0]}"
node tests/desktop.mjs "$@"
