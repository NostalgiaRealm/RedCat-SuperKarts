/*
 * FUN_00407d58 at 00407d58
 * undefined4 __register FUN_00407d58(char * param_1, char * param_2)
 * Address ranges: 00407d58-00407d7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407d58(char *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    if (param_1 == (char *)0x0) {
      return 0;
    }
    if ((param_2 == (char *)0x0) || (*(int *)(param_1 + -4) != *(int *)(param_2 + -4))) {
      return 0;
    }
    iVar1 = FUN_00407d04(param_1,param_2);
    param_1 = (char *)0x0;
    if (iVar1 != 0) {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

