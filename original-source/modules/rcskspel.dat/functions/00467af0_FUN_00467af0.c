/*
 * FUN_00467af0 at 00467af0
 * undefined FUN_00467af0(void)
 * Address ranges: 00467af0-00467be0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00467af0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cfb98;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x8c))();
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x90) + 4) + iVar3 * 4);
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if (*(undefined4 **)(param_1 + 0x94) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x94))(1);
  }
  if (*(undefined4 **)(param_1 + 0x98) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x98))(1);
  }
  if (*(undefined4 **)(param_1 + 0x9c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x9c))(1);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0xa0));
  iVar2 = *(int *)(param_1 + 0x90);
  *(undefined ***)(param_1 + 0x8c) = &PTR_FUN_004d2cd8;
  if (iVar2 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar2 + 4));
    *(undefined4 *)(iVar2 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    FUN_004bc150(iVar2);
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  local_4 = 0xffffffff;
  FUN_00460580();
  ExceptionList = pvStack_c;
  return;
}

