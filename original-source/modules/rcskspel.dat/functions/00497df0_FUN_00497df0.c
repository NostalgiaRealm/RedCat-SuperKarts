/*
 * FUN_00497df0 at 00497df0
 * undefined FUN_00497df0(void)
 * Address ranges: 00497df0-00497ef7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00497df0(void)

{
  int iVar1;
  int iVar2;
  
  DAT_00680bac = 0;
  _strncpy(&DAT_00680bb4,s_cameras_004fb35c,0x19);
  _strncpy(&DAT_00680bcd,s_c_camera_004fb350,0x19);
  if (DAT_00680bac != 0) {
    if ((DAT_00680bac == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680bcd,&DAT_00680bb4,
                     DAT_00680ba4), DAT_00680ba0 != 0)) {
      iVar2 = *(int *)(DAT_00680ba0 + -4);
      iVar1 = DAT_00680ba0 + -4;
      if (-1 < iVar2 + -1) {
        do {
          FUN_00498700();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_004bc150(iVar1);
    }
    if (DAT_00680bac != 0) {
      FUN_004bc150(DAT_00680bb0);
      DAT_00680bac = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_00680ba0 = 0;
  DAT_00680ba4 = 0;
  DAT_00680ba8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_00680bcd,&DAT_00680bb4,0);
  DAT_00680bb0 = 0;
  DAT_00680bac = 0;
  FUN_004be654(FUN_00497f00);
  return;
}

