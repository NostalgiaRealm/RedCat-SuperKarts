/*
 * FUN_00451200 at 00451200
 * undefined FUN_00451200(void)
 * Address ranges: 00451200-004512a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00451200(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__Handle_004f13d8);
  if (DAT_00543d28 != '\0') {
    FUN_004524c0();
  }
  iVar2 = 0;
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x20))();
  if (0 < iVar1) {
    do {
      FUN_00452020(iVar2);
      FUN_00453780();
      iVar2 = iVar2 + 1;
      iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x20))();
    } while (iVar2 < iVar1);
  }
  iVar2 = 0;
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x30))();
  if (0 < iVar1) {
    do {
      FUN_004521c0(iVar2);
      FUN_00453fd0();
      iVar2 = iVar2 + 1;
      iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x30))();
    } while (iVar2 < iVar1);
  }
  iVar2 = 0;
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x28))();
  if (0 < iVar1) {
    do {
      FUN_00452280(iVar2);
      FUN_00455a10();
      iVar2 = iVar2 + 1;
      iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x28))();
    } while (iVar2 < iVar1);
  }
  FUN_00456350();
  return;
}

