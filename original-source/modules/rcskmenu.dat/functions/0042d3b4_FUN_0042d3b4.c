/*
 * FUN_0042d3b4 at 0042d3b4
 * undefined __register FUN_0042d3b4(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0042d3b4-0042d3d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d3b4(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0x216);
  FUN_0042d2b4(param_1,param_2,param_3);
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0xb0))();
  }
  return;
}

