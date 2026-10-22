/** Original 46fd98/46fdc4, 474234/474268 and 477284/4772b0. */
export function nativeMenuNavigationSound(direction) { return direction > 0 ? 47 : 48; }

/** 45d4a0 reads FIRSTTIME/<phase> with integer default1, retains its low
 * byte, then writes0. Shipped settings already contain0 for all four forms.
 * Browser persistence records a prior visit; absence must use the INI value.
 */
export function nativeMenuFirstTime(config, phase, visited = false) {
  if (visited) return false;
  const value = config['ini/settings.ini']?.firsttime?.[phase.toLowerCase()];
  const number = value === undefined || String(value).trim() === '' ? 1 : Number(value);
  return Boolean((Number.isInteger(number) ? number : 1) & 255);
}

/** Main FormShow474b00 performs no random draw or intro-dependent branch. */
export function nativeMainMenuGreeting(firstTime) { return firstTime ? 0 : 1; }

/** 46fefc/46ff20/46ff44: the selected character names the race mode. */
export function nativeMenuRaceModeSound(mode) { return 10 + mode; }

/** 477d30..477d80, byte tables at47c584 and47c59c.
 * Country order is the shell's Netherlands/Germany/England/France/Spain/Italy. */
export function nativeCountryInfoSound(country, photo = null) {
  if (!Number.isInteger(country) || country < 0 || country > 5)
    throw new RangeError('Invalid original country');
  if (photo !== null && (!Number.isInteger(photo) || photo < 0 || photo > 3))
    throw new RangeError('Invalid original country photograph');
  return 80 + country * 5 + (photo === null ? 0 : photo + 1);
}

/** 461958 accepts letters, Enter, Shift/Ctrl/Alt and Space..Down.
 * Escape cancels; other keys play generic110 and leave capture active. */
export function nativeMenuBindingKey(keyCode) {
  if (keyCode === 27) return 'cancel';
  return keyCode >= 65 && keyCode <= 90 || keyCode === 13 ||
    keyCode >= 16 && keyCode <= 18 || keyCode >= 32 && keyCode <= 40 ? 'accept' : 'reject';
}
