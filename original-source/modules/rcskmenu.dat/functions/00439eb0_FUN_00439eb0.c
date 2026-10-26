/*
 * FUN_00439eb0 at 00439eb0
 * undefined __register FUN_00439eb0(int * param_1, int * param_2)
 * Address ranges: 00439eb0-00439ed9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439eb0(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    iVar1 = FUN_0040303c(param_2,(int)&PTR_FUN_0043b888);
    FUN_00439e64(param_1,*(char *)(iVar1 + 0x4f));
    *(undefined1 *)((int)param_1 + 0x35) = 1;
  }
  return;
}

