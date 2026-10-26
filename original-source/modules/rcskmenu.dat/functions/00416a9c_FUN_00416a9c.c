/*
 * FUN_00416a9c at 00416a9c
 * uint __register FUN_00416a9c(byte * param_1, int param_2)
 * Address ranges: 00416a9c-00416aac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00416a9c(byte *param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    sVar1 = (short)uVar2 << 5;
    uVar2 = (uint)CONCAT11((char)((ushort)sVar1 >> 8),
                           ((byte)sVar1 | (byte)(uVar2 >> 8) >> 3) ^ *param_1);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return uVar2;
}

