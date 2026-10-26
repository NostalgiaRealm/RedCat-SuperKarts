/*
 * FUN_004233c0 at 004233c0
 * undefined FUN_004233c0(void)
 * Address ranges: 004233c0-00423442
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004233c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_00680ba0 + (&DAT_00508620)[DAT_00508670] * 0x178;
  puVar3 = (undefined4 *)(iVar1 + 0x14);
  puVar4 = &DAT_00509160;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  _DAT_00509190 = *(undefined4 *)(iVar1 + 8);
  _DAT_00509194 = *(undefined4 *)(iVar1 + 0xc);
  _DAT_00509198 = *(undefined4 *)(iVar1 + 0x10);
  FUN_00423280();
  DAT_0050bc24 = DAT_0050bc24 + 1;
  if (DAT_0050bc20 <= DAT_0050bc24) {
    DAT_0050bc24 = 0;
  }
  return;
}

