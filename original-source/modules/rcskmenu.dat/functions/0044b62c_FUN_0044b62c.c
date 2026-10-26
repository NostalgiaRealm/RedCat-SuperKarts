/*
 * FUN_0044b62c at 0044b62c
 * undefined __register FUN_0044b62c(int * param_1, UINT * param_2, undefined4 param_3)
 * Address ranges: 0044b62c-0044b665;0044b681-0044b69e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b62c(int *param_1,UINT *param_2,undefined4 param_3)

{
  UINT UVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  
  if (*param_2 == 0x113) {
    uVar2 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffe0;
    FUN_00403088(param_1,param_2,param_3);
    *in_FS_OFFSET = uVar2;
  }
  else {
    UVar1 = DefWindowProcA((HWND)param_1[10],*param_2,param_2[1],param_2[2]);
    param_2[3] = UVar1;
  }
  return;
}

