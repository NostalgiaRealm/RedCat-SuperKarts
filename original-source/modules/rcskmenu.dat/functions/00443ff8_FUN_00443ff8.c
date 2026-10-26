/*
 * FUN_00443ff8 at 00443ff8
 * undefined __register FUN_00443ff8(int param_1, char * param_2, undefined4 * param_3)
 * Address ranges: 00443ff8-0044401b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443ff8(int param_1,char *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_00414c8c(*(int *)(param_1 + 4),param_2);
  uVar2 = FUN_0040303c(piVar1,(int)&PTR_FUN_0043b888);
  *param_3 = uVar2;
  return;
}

