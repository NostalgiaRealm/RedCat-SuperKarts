/*
 * FUN_0041dc60 at 0041dc60
 * undefined FUN_0041dc60(void)
 * Address ranges: 0041dc60-0041dcb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041dc60(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined4 uStack_60;
  int iStack_5c;
  int iStack_44;
  
  bVar5 = 0;
  iVar1 = param_1[8];
  if (param_2 != *(int *)(iVar1 + 0x1c)) {
    FUN_0041cf14((int)param_1);
    puVar3 = (undefined4 *)(iVar1 + 0x18);
    puVar4 = &uStack_60;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    iStack_5c = param_2;
    iStack_44 = param_2;
    FUN_0041c984((int)param_1,*(HBITMAP *)(iVar1 + 8),*(HPALETTE *)(iVar1 + 0x10),&uStack_60);
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

