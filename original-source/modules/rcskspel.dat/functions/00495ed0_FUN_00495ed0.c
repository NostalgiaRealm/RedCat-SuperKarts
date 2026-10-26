/*
 * FUN_00495ed0 at 00495ed0
 * undefined FUN_00495ed0(void)
 * Address ranges: 00495ed0-00495fdf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00495ed0(float param_1,undefined4 param_2,float param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
  local_4 = 0;
  bVar3 = param_3 <= (*(float **)(param_4 + 8))[2];
  if (param_1 <= **(float **)(param_4 + 8)) {
    if (bVar3) {
      uVar5 = 0;
    }
    else {
      uVar5 = 3;
    }
  }
  else if (bVar3) {
    uVar5 = 1;
  }
  else {
    uVar5 = 2;
  }
  iVar6 = 8;
  iVar7 = 0;
  do {
    pfVar1 = *(float **)(iVar7 + param_4);
    if (param_1 <= *pfVar1) {
      if (param_3 <= pfVar1[2]) {
        uVar4 = 0;
      }
      else {
        uVar4 = 3;
      }
    }
    else if (param_3 <= pfVar1[2]) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    if (uVar5 != uVar4) {
      if ((uVar5 + 1 & 3) == uVar4) {
        local_4 = local_4 + 1;
      }
      else if ((uVar4 + 1 & 3) == uVar5) {
        local_4 = local_4 + -1;
      }
      else {
        pfVar2 = *(float **)(iVar6 + param_4);
        if (0.0 < (param_3 - pfVar2[2]) * (*pfVar1 - *pfVar2) -
                  (param_1 - *pfVar2) * (pfVar1[2] - pfVar2[2])) {
          local_4 = local_4 + 2;
        }
        else {
          local_4 = local_4 + -2;
        }
      }
    }
    iVar8 = iVar7 + 4;
    uVar5 = uVar4;
    iVar6 = iVar7;
    iVar7 = iVar8;
  } while (iVar8 < 0xc);
  return CONCAT31((int3)((uint)local_4 >> 8),local_4 != 0);
}

