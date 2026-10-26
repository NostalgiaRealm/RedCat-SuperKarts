/*
 * FUN_0040be98 at 0040be98
 * int * __register FUN_0040be98(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0040be98-0040befd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0040be98(int *param_1,char param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  undefined4 extraout_ECX;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,-1,-1,(LPCSTR)0x0);
  param_1[7] = (int)pvVar1;
  FUN_00404e50(param_1 + 10,(int)&DAT_00407b04,1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

