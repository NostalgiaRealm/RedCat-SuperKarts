/*
 * FUN_00418e76 at 00418e76
 * undefined4 __cdecl FUN_00418e76(int param_1, int param_2, int param_3, uint * param_4, int * param_5, uint * param_6)
 * Address ranges: 00418e76-004191a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl
FUN_00418e76(int param_1,int param_2,int param_3,uint *param_4,int *param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  MMRESULT MVar3;
  UINT local_c;
  
  uVar1 = param_2 / 2;
  iVar2 = param_3 / 2;
  if (param_1 == 1) {
    local_c = 0;
  }
  else if (param_1 == 2) {
    local_c = 1;
  }
  else {
    FUN_0040187a((byte *)s__get_joystick_position__invalid_j_00435e54);
  }
  if (*(int *)(&DAT_0043dce8 + param_1 * 0x5c) != 0) {
    *param_6 = 0;
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar3 = joyGetPosEx(local_c,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar3 == 0) {
      if ((double)DAT_0043dcb8 <=
          (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 +
          (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c)) {
        if ((double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
            (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 <= (double)DAT_0043dcb8
           ) {
          *param_4 = uVar1;
        }
        else {
          *param_4 = DAT_0043dcb8 /
                     (uint)((*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
                            *(int *)(&DAT_0043dd38 + param_1 * 0x5c)) / (int)uVar1);
          *param_6 = *param_6 | 4;
        }
      }
      else {
        *param_4 = DAT_0043dcb8 /
                   (uint)((*(int *)(&DAT_0043dd34 + param_1 * 0x5c) -
                          *(int *)(&DAT_0043dd2c + param_1 * 0x5c)) / (int)uVar1);
        *param_6 = *param_6 | 8;
      }
      if ((double)DAT_0043dcbc <=
          (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 +
          (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c)) {
        if ((double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
            (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 <= (double)DAT_0043dcbc
           ) {
          *param_5 = iVar2;
        }
        else {
          *param_5 = iVar2 * 2 -
                     DAT_0043dcbc /
                     (uint)((*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
                            *(int *)(&DAT_0043dd40 + param_1 * 0x5c)) / iVar2);
          *param_6 = *param_6 | 1;
        }
      }
      else {
        *param_5 = iVar2 * 2 -
                   DAT_0043dcbc /
                   (uint)((*(int *)(&DAT_0043dd3c + param_1 * 0x5c) -
                          *(int *)(&DAT_0043dd30 + param_1 * 0x5c)) / iVar2);
        *param_6 = *param_6 | 2;
      }
      if ((DAT_0043dcd0 & 1) != 0) {
        *param_6 = *param_6 | 0x10;
      }
      if ((DAT_0043dcd0 & 2) != 0) {
        *param_6 = *param_6 | 0x20;
      }
      if ((DAT_0043dcd0 & 4) != 0) {
        *param_6 = *param_6 | 0x40;
      }
      if ((DAT_0043dcd0 & 8) != 0) {
        *param_6 = *param_6 | 0x80;
      }
      return 1;
    }
  }
  return 0;
}

