/*
 * FUN_00443398 at 00443398
 * bool __register FUN_00443398(HWND param_1, int * param_2)
 * Address ranges: 00443398-004433ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00443398(HWND param_1,int *param_2)

{
  HANDLE pvVar1;
  int iVar2;
  
  pvVar1 = FUN_0043c864(param_1);
  if (pvVar1 != (HANDLE)0x0) {
    iVar2 = FUN_004405f0((int)pvVar1,*param_2 + 0xbc00,param_2[1],param_2[2]);
    param_2[3] = iVar2;
  }
  return pvVar1 != (HANDLE)0x0;
}

