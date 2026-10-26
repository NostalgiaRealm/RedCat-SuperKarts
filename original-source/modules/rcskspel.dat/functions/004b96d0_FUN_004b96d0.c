/*
 * FUN_004b96d0 at 004b96d0
 * undefined FUN_004b96d0(void)
 * Address ranges: 004b96d0-004b9833
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004b96d0(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((DAT_006ab944 == 0) || (DAT_006ab948 == 1)) {
    iVar2 = FUN_004bf445(param_1,&DAT_005012c0);
    if (iVar2 == 0) {
      FUN_004afce0(s__s__d____file_open_failed___s__00501a44,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x117,param_1);
      return 0;
    }
    uVar4 = 0x11c;
  }
  else {
    iVar2 = 0;
    if (0 < _DAT_006ab938) {
      iVar3 = 0;
      do {
        iVar1 = __strcmpi((char *)(iVar3 + DAT_006ab93c),param_1);
        if (iVar1 == 0) {
          DAT_006ab940 = *(int *)(DAT_006ab93c + 0x14 + iVar2 * 0x1c);
          DAT_006ab92c = *(int *)(DAT_006ab93c + iVar2 * 0x1c + 0x18) + DAT_006ab940;
          break;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x1c;
      } while (iVar2 < _DAT_006ab938);
    }
    iVar3 = (int)DAT_006ab938;
    if (iVar2 != iVar3) {
      uVar4 = FUN_004c0331(DAT_006ab934,DAT_006ab940,0);
      uVar4 = FUN_004ccbb9(DAT_006ab934,uVar4);
      FUN_004afce0(s__s__d____file_open_succeeded___s_00501a0c,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x156,param_1,iVar2,iVar3,DAT_006ab940,
                   uVar4);
      return DAT_006ab934;
    }
    iVar2 = FUN_004bf445(param_1,&DAT_005012c0);
    if (iVar2 == 0) {
      FUN_004afce0(s__s__d____file_open_failed___s__00501a44,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x14b,param_1);
      return 0;
    }
    uVar4 = 0x150;
  }
  FUN_004afce0(s__s__d____file_open_succeeded___s_005019e4,s_C__libraries_dxdraw_Fileio_cpp_00501928
               ,uVar4,param_1);
  return iVar2;
}

