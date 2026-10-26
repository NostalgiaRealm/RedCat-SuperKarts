/*
 * FUN_00444efc at 00444efc
 * bool __register FUN_00444efc(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 00444efc-00444f8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00444efc(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  LRESULT LVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar5;
  
  piVar3 = param_1;
  iVar5 = param_2;
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[9]) {
      piVar2 = (int *)FUN_00403088(piVar3,iVar5,param_3);
      param_3 = extraout_ECX;
      iVar5 = extraout_EDX;
      if (((piVar2 != (int *)0x0) && (piVar2[0xb] != 0)) &&
         (cVar1 = FUN_00403088(piVar2,param_2,extraout_ECX), param_3 = extraout_ECX_00,
         iVar5 = extraout_EDX_00, cVar1 != '\0')) {
        return true;
      }
    }
    piVar3 = FUN_004298bc(param_1);
    if ((piVar3 != (int *)0x0) &&
       (cVar1 = FUN_00403088(piVar3,param_2,extraout_ECX_01), cVar1 != '\0')) {
      return true;
    }
  }
  LVar4 = FUN_0043c880(0xb016,(uint)*(ushort *)(param_2 + 4),*(LPARAM *)(param_2 + 8));
  return LVar4 != 0;
}

