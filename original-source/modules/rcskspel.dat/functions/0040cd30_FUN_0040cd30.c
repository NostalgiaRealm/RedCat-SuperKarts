/*
 * FUN_0040cd30 at 0040cd30
 * undefined FUN_0040cd30(void)
 * Address ranges: 0040cd30-0040cdd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040cd30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_0040fb40();
  iVar2 = FUN_0040fb90();
  cVar1 = FUN_00417e90(param_1);
  uVar3 = DAT_0053be60;
  if (cVar1 == '\0') {
    uVar3 = (&DAT_005081b8)[param_1 * 0x1c];
  }
  iVar4 = FUN_004100c0(uVar3);
  iVar2 = (iVar4 * iVar2) / 100;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  FUN_0040cd10(*(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20),iVar2);
  return 0;
}

