/*
 * FUN_00425048 at 00425048
 * bool __cdecl FUN_00425048(int * param_1)
 * Address ranges: 00425048-004251f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_00425048(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_00437994 != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_00437a28) || (uVar5 != DAT_00437a38)) {
      if (DAT_0043e480 == 0) {
        FUN_004251f4(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_004251f4(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_0043e520 != 0) {
          uVar6 = (uint)DAT_0043e526;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_0043e524;
          uVar6 = 0;
          uVar4 = (uint)DAT_0043e526;
        }
        FUN_004251f4(1,(uint)(DAT_0043e520 == 0),uVar5,(uint)DAT_0043e522,uVar4,uVar3,uVar6,
                     (uint)DAT_0043e528,(uint)DAT_0043e52a,(uint)DAT_0043e52c,(uint)DAT_0043e52e);
        if (DAT_0043e4cc != 0) {
          uVar6 = (uint)DAT_0043e4d2;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_0043e4d0;
          uVar6 = 0;
          uVar4 = (uint)DAT_0043e4d2;
          uVar5 = param_1[5];
        }
        FUN_004251f4(0,(uint)(DAT_0043e4cc == 0),uVar5,(uint)DAT_0043e4ce,uVar4,uVar3,uVar6,
                     (uint)DAT_0043e4d4,(uint)DAT_0043e4d6,(uint)DAT_0043e4d8,(uint)DAT_0043e4da);
      }
    }
    iVar1 = param_1[7];
    if (DAT_00437a2c < DAT_00437a3c) {
      if ((DAT_00437a2c <= iVar1) && (iVar1 <= DAT_00437a3c)) {
        if ((DAT_00437a2c < iVar1) && (iVar1 < DAT_00437a3c)) {
          return true;
        }
LAB_004251c0:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_00437a2c) {
          return DAT_00437a30 <= iVar2;
        }
        return iVar2 < DAT_00437a40;
      }
    }
    else {
      if (iVar1 < DAT_00437a3c) {
        return true;
      }
      if (DAT_00437a2c < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_00437a3c) || (DAT_00437a2c <= iVar1)) goto LAB_004251c0;
    }
  }
  return false;
}

