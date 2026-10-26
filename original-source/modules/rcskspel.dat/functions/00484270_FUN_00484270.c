/*
 * FUN_00484270 at 00484270
 * undefined FUN_00484270(void)
 * Address ranges: 00484270-004842e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00484270(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xa0)) {
    iVar4 = 0;
    do {
      iVar2 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x88) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x9c) + 0x14 + iVar4);
      iVar4 = iVar4 + 0x5c;
      *puVar1 = *(undefined4 *)(iVar2 + 0x50);
      puVar1[1] = *(undefined4 *)(iVar2 + 0x54);
      puVar1[2] = *(undefined4 *)(iVar2 + 0x58);
    } while (iVar3 < *(int *)(param_1 + 0xa0));
  }
  FUN_00483280(param_2);
  return;
}

