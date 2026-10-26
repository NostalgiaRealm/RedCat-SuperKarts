/*
 * FUN_00411c94 at 00411c94
 * LPCVOID __register FUN_00411c94(int param_1, SIZE_T * param_2)
 * Address ranges: 00411c94-00411d15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LPCVOID FUN_00411c94(int param_1,SIZE_T *param_2)

{
  int *piVar1;
  LPCVOID pvVar2;
  LPCVOID extraout_ECX;
  
  if (0 < (int)*param_2) {
    *param_2 = *param_2 + 0x1fff & 0xffffe000;
  }
  pvVar2 = *(LPCVOID *)(param_1 + 4);
  if (*param_2 != *(SIZE_T *)(param_1 + 0x10)) {
    if (*param_2 == 0) {
      FUN_00406c00(pvVar2);
      pvVar2 = (LPCVOID)0x0;
    }
    else {
      if (*(SIZE_T *)(param_1 + 0x10) == 0) {
        pvVar2 = (LPCVOID)FUN_00406bd4((uint)*(ushort *)PTR_DAT_0047c90c,*param_2);
      }
      else {
        pvVar2 = (LPCVOID)FUN_00406be4(pvVar2,*param_2,(uint)*(ushort *)PTR_DAT_0047c90c);
      }
      if (pvVar2 == (LPCVOID)0x0) {
        piVar1 = FUN_0040ad20((int *)&DAT_0040d974,'\x01',(undefined4 *)PTR_PTR_0047c980);
        FUN_00403604(piVar1);
        pvVar2 = extraout_ECX;
      }
    }
  }
  return pvVar2;
}

