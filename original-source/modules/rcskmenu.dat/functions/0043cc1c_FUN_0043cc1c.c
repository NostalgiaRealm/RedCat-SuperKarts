/*
 * FUN_0043cc1c at 0043cc1c
 * undefined __register FUN_0043cc1c(int * param_1, undefined4 param_2)
 * Address ranges: 0043cc1c-0043cc74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cc1c(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  HWND pHVar3;
  int local_c;
  undefined4 local_8;
  
  local_8 = param_2;
  puVar2 = (undefined4 *)FUN_00402714(8);
  *puVar2 = local_8;
  pHVar3 = FUN_0043cbf4();
  puVar2[1] = pHVar3;
  cVar1 = FUN_0043cbc0(param_1,(int)pHVar3,&local_c);
  if (cVar1 == '\0') {
    FUN_0040f504(param_1,(int)puVar2);
  }
  else {
    FUN_0040f72c(param_1,local_c,(int)puVar2);
  }
  return;
}

