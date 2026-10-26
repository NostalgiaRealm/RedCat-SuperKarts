/*
 * FUN_004bac90 at 004bac90
 * undefined FUN_004bac90(void)
 * Address ranges: 004bac90-004baeb5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004bac90(int param_1,int param_2,int param_3,uint *param_4,int *param_5,uint *param_6)

{
  int iVar1;
  double dVar2;
  uint *uJoyID;
  MMRESULT MVar3;
  uint uVar4;
  
  uVar4 = param_2 / 2;
  param_3 = param_3 / 2;
  if (param_1 == 1) {
    uJoyID = (uint *)0x0;
  }
  else if (param_1 == 2) {
    uJoyID = (uint *)0x1;
  }
  else {
    FUN_004afee0(s__get_joystick_position__invalid_j_005021f0,param_1);
    uJoyID = param_4;
  }
  param_1 = param_1 * 0x5c;
  if (*(int *)(&DAT_006ab9c0 + param_1) != 0) {
    *param_6 = 0;
    _DAT_006ab988 = 0x34;
    _DAT_006ab98c = 0x83;
    MVar3 = joyGetPosEx((UINT)uJoyID,(LPJOYINFOEX)&DAT_006ab988);
    if (MVar3 == 0) {
      iVar1 = *(int *)(&DAT_006aba04 + param_1);
      dVar2 = (double)iVar1;
      if ((double)DAT_006ab990 <= dVar2 * _DAT_00502060 + dVar2) {
        if (dVar2 - dVar2 * _DAT_00502060 <= (double)DAT_006ab990) {
          *param_4 = uVar4;
        }
        else {
          *param_4 = DAT_006ab990 / (uint)((iVar1 - *(int *)(&DAT_006aba10 + param_1)) / (int)uVar4)
          ;
          *param_6 = *param_6 | 4;
        }
      }
      else {
        *param_4 = DAT_006ab990 / (uint)((*(int *)(&DAT_006aba0c + param_1) - iVar1) / (int)uVar4);
        *param_6 = *param_6 | 8;
      }
      iVar1 = *(int *)(&DAT_006aba08 + param_1);
      dVar2 = (double)iVar1;
      if ((double)DAT_006ab994 <= dVar2 * _DAT_00502060 + dVar2) {
        if (dVar2 - dVar2 * _DAT_00502060 <= (double)DAT_006ab994) {
          *param_5 = param_3;
        }
        else {
          *param_5 = param_3 * 2 -
                     DAT_006ab994 / (uint)((iVar1 - *(int *)(&DAT_006aba18 + param_1)) / param_3);
          *param_6 = *param_6 | 1;
        }
      }
      else {
        *param_5 = param_3 * 2 -
                   DAT_006ab994 / (uint)((*(int *)(&DAT_006aba14 + param_1) - iVar1) / param_3);
        *param_6 = *param_6 | 2;
      }
      if (((byte)DAT_006ab9a8 & 1) != 0) {
        *param_6 = *param_6 | 0x10;
      }
      if (((byte)DAT_006ab9a8 & 2) != 0) {
        *param_6 = *param_6 | 0x20;
      }
      if (((byte)DAT_006ab9a8 & 4) != 0) {
        *param_6 = *param_6 | 0x40;
      }
      if (((byte)DAT_006ab9a8 & 8) != 0) {
        *param_6 = *param_6 | 0x80;
      }
      return 1;
    }
  }
  return 0;
}

