/*
 * FUN_0043f868 at 0043f868
 * undefined __register FUN_0043f868(int * param_1, char param_2)
 * Address ranges: 0043f868-0043f88f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f868(int *param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = FUN_0043f858(param_1);
  if ((bool)param_2 != bVar1) {
    if (param_2 == '\0') {
      FUN_0043cb14((int *)0x0);
    }
    else {
      FUN_0043cb14(param_1);
    }
  }
  return;
}

