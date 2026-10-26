/*
 * FUN_00497f00 at 00497f00
 * undefined FUN_00497f00(void)
 * Address ranges: 00497f00-00498065
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00497f00(void)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  if ((DAT_00680bac == 1) &&
     (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680bcd,&DAT_00680bb4,
                   DAT_00680ba4), DAT_00680ba0 != 0)) {
    iStack_8 = *(int *)(DAT_00680ba0 + -4);
    iVar1 = DAT_00680ba0 + -4;
    if (-1 < iStack_8 + -1) {
      iVar2 = DAT_00680ba0 + iStack_8 * 0x178 + 0x146;
      do {
        FUN_00405f70();
        FUN_00405f70();
        if (*(int *)(iVar2 + -0x180) == 1) {
          FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,iVar2 + -0x15f,iVar2 + -0x178,
                       *(undefined4 *)(iVar2 + -0x188));
          FUN_004bc150(*(undefined4 *)(iVar2 + -0x18c));
        }
        if (*(int *)(iVar2 + -0x180) != 0) {
          FUN_004bc150(*(undefined4 *)(iVar2 + -0x17c));
          *(undefined4 *)(iVar2 + -0x180) = 0;
        }
        FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
        if (*(int *)(iVar2 + -0x1c6) == 1) {
          FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,iVar2 + -0x1a5,iVar2 + -0x1be,
                       *(undefined4 *)(iVar2 + -0x1ce));
          FUN_004bc150(*(undefined4 *)(iVar2 + -0x1d2));
        }
        if (*(int *)(iVar2 + -0x1c6) != 0) {
          FUN_004bc150(*(undefined4 *)(iVar2 + -0x1c2));
          *(undefined4 *)(iVar2 + -0x1c6) = 0;
        }
        FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
        iStack_8 = iStack_8 + -1;
        iVar2 = iVar2 + -0x178;
      } while (iStack_8 != 0);
    }
    FUN_004bc150(iVar1);
  }
  if (DAT_00680bac != 0) {
    FUN_004bc150(DAT_00680bb0);
    DAT_00680bac = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

