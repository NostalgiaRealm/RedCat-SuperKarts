/*
 * FUN_004136e0 at 004136e0
 * undefined __register FUN_004136e0(int * param_1, undefined4 * param_2, undefined4 param_3)
 * Address ranges: 004136e0-00413724
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004136e0(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  code *pcVar2;
  int local_c;
  int *local_8;
  
  local_8 = param_1;
  pcVar2 = (code *)FUN_0040f0e8(*(int *)*param_2);
  if ((pcVar2 != (code *)0x0) && (cVar1 = (*pcVar2)(param_3,&local_c), cVar1 != '\0')) {
    FUN_0040d3f4(local_8,param_2,local_c);
    return;
  }
  FUN_004124c0();
  return;
}

