/*
 * FUN_00435cf0 at 00435cf0
 * char __register FUN_00435cf0(int * param_1, int param_2, undefined * param_3, int param_4)
 * Address ranges: 00435cf0-00435d4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_00435cf0(int *param_1,int param_2,undefined *param_3,int param_4)

{
  int iVar1;
  char local_d;
  
  if (param_2 != 0) {
    local_d = '\0';
    while (local_d == '\0') {
      iVar1 = FUN_00438084(param_2);
      if (iVar1 <= *param_1) {
        return '\0';
      }
      iVar1 = FUN_00438094(param_2,*param_1);
      if (*(byte *)(param_4 + -1) < *(byte *)(iVar1 + 0x33)) {
        return '\0';
      }
      local_d = (*(code *)param_3)(iVar1);
      *param_1 = *param_1 + 1;
    }
  }
  return local_d;
}

