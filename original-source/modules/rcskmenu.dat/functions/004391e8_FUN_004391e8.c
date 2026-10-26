/*
 * FUN_004391e8 at 004391e8
 * undefined1 __register FUN_004391e8(int param_1)
 * Address ranges: 004391e8-00439213
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004391e8(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x30);
  if ((*(byte *)(param_1 + 0x30) == 2) && (*(int *)(param_1 + 0x58) != 0)) {
    bVar1 = FUN_004391e8(*(int *)(param_1 + 0x58));
    uVar2 = (uint)(byte)(&DAT_0047b818)[bVar1 & 0x7f];
  }
  return (&DAT_0047b81c)[uVar2 & 0x7f];
}

