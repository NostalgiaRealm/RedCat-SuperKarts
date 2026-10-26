/*
 * FUN_00416a28 at 00416a28
 * undefined __register FUN_00416a28(HGDIOBJ param_1)
 * Address ranges: 00416a28-00416a3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416a28(HGDIOBJ param_1)

{
  if ((param_1 != (HGDIOBJ)0x0) && (param_1 != DAT_0047d67c)) {
    DeleteObject(param_1);
  }
  return;
}

