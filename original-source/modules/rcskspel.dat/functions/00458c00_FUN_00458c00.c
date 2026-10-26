/*
 * FUN_00458c00 at 00458c00
 * undefined FUN_00458c00(void)
 * Address ranges: 00458c00-00458c45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458c00(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00544aa8 != '\0') {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x74))();
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x78) + 4) + iVar2 * 4) + 0x28))
                  (param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    FUN_00458570(param_2);
  }
  return;
}

