/*
 * FUN_00486cc0 at 00486cc0
 * undefined FUN_00486cc0(void)
 * Address ranges: 00486cc0-00486d4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00486cc0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  iVar2 = 8;
  do {
    puVar1[-1] = 0x3edc0000;
    *puVar1 = 0x3e080000;
    puVar1[7] = 0x3ee80000;
    puVar1[8] = 0x3e080000;
    puVar1[0xf] = 0x3ee80000;
    puVar1[0x10] = 0x3e200000;
    puVar1[0xbf] = 0x3edc0000;
    puVar1[0xc0] = 0x3e080000;
    puVar1[199] = 0x3ee80000;
    puVar1[200] = 0x3e080000;
    puVar1[0xcf] = 0x3ee80000;
    puVar1[0xd0] = 0x3e200000;
    puVar1 = puVar1 + 0x18;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

