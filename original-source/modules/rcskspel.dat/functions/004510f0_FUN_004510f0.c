/*
 * FUN_004510f0 at 004510f0
 * undefined FUN_004510f0(void)
 * Address ranges: 004510f0-004511bc;004511ec-004511fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004510f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004cdbe1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004afce0(s_CBonusController__Exit_004f1378);
  local_8 = 0;
  iVar3 = 0;
  while( true ) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x20))();
    if (iVar2 <= iVar3) break;
    puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x24) + 4) + iVar3 * 4);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    iVar3 = iVar3 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + -4 + iVar3 * 4) = 0;
  }
  iVar3 = 0;
  while( true ) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x28))();
    if (iVar2 <= iVar3) break;
    puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + iVar3 * 4);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    iVar3 = iVar3 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + -4 + iVar3 * 4) = 0;
  }
  iVar3 = 0;
  while( true ) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x20))();
    if (iVar2 <= iVar3) break;
    puVar1 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x34) + 4) + iVar3 * 4);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    iVar3 = iVar3 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x34) + 4) + -4 + iVar3 * 4) = 0;
  }
  ExceptionList = local_10;
  return;
}

