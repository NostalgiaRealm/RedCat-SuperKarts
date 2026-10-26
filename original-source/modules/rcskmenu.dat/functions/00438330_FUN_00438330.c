/*
 * FUN_00438330 at 00438330
 * undefined FUN_00438330(void)
 * Address ranges: 00438330-0043839f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438330(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2d) != '\0') {
    if (((*(short *)(param_1 + 0x82) != 0) && (iVar1 = FUN_0043806c(param_1), iVar1 != 0)) &&
       (iVar1 = FUN_0043806c(param_1), *(int *)(iVar1 + 0x30) != *(int *)(param_1 + 0x80))) {
      (**(code **)(param_1 + 0x80))(*(undefined4 *)(param_1 + 0x84),param_1);
      return;
    }
    if (((*(byte *)(param_1 + 0x20) & 0x10) == 0) && (*(int *)(param_1 + 0x38) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x38) + 0x18))();
    }
    else if (*(short *)(param_1 + 0x82) != 0) {
      (**(code **)(param_1 + 0x80))(*(undefined4 *)(param_1 + 0x84),param_1);
    }
  }
  return;
}

