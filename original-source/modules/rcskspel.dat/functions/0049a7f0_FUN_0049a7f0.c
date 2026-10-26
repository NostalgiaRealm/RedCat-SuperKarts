/*
 * FUN_0049a7f0 at 0049a7f0
 * undefined FUN_0049a7f0(void)
 * Address ranges: 0049a7f0-0049ab03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_0049a7f0(float param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5
                    ,float param_6,float param_7,undefined4 param_8,float param_9,float param_10,
                    undefined4 param_11,float param_12,int *param_13)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10 [4];
  
  local_14 = param_4 - param_1;
  local_18 = param_6 - param_3;
  if ((local_14 != 0.0) || (local_18 != 0.0)) {
    local_10[3] = param_1 - param_7;
    local_10[1] = param_10 - param_1;
    local_10[0] = param_3 - param_9;
    local_10[2] = param_12 - param_3;
    if ((0.0 < param_1 - param_7) &&
       (((0.0 < param_10 - param_1 && (0.0 < param_3 - param_9)) && (0.0 < param_12 - param_3)))) {
      fVar1 = 3.4028235e+38;
      iVar6 = -1;
      iVar3 = 0;
      pfVar5 = local_10;
      do {
        if (*pfVar5 < fVar1) {
          fVar1 = *pfVar5;
          iVar6 = iVar3;
        }
        iVar3 = iVar3 + 1;
        pfVar5 = pfVar5 + 1;
      } while (iVar3 < 4);
      if (iVar6 != -1) {
        local_10[3] = param_4 - param_7;
        local_10[1] = param_10 - param_4;
        local_10[0] = param_6 - param_9;
        local_10[2] = param_12 - param_6;
        if (((0.0 < param_4 - param_7) && (0.0 < param_10 - param_4)) &&
           ((0.0 < param_6 - param_9 && (0.0 < param_12 - param_6)))) {
          fVar1 = 3.4028235e+38;
          iVar3 = -1;
          iVar4 = 0;
          pfVar5 = local_10;
          do {
            if (*pfVar5 < fVar1) {
              fVar1 = *pfVar5;
              iVar3 = iVar4;
            }
            iVar4 = iVar4 + 1;
            pfVar5 = pfVar5 + 1;
          } while (iVar4 < 4);
          if (iVar3 != -1) {
            *param_13 = iVar6;
            return (float10)0.0;
          }
        }
        goto LAB_0049aaf8;
      }
    }
    param_4 = 0.0;
    local_1c = 0x3f800000;
    local_20 = 0.0;
    iVar6 = FUN_0049a750(local_14,param_7 - param_1,&param_4,&local_1c);
    piVar2 = param_13;
    if (iVar6 != 0) {
      if (param_4 != 0.0) {
        *param_13 = 3;
        local_20 = param_4;
      }
      iVar6 = FUN_0049a750(-local_14,param_1 - param_10,&param_4,&local_1c);
      if (iVar6 != 0) {
        if (param_4 != local_20) {
          *piVar2 = 1;
          local_20 = param_4;
        }
        iVar6 = FUN_0049a750(local_18,param_9 - param_3,&param_4,&local_1c);
        if (iVar6 != 0) {
          if (param_4 != local_20) {
            *piVar2 = 0;
            local_20 = param_4;
          }
          iVar6 = FUN_0049a750(-local_18,param_3 - param_12,&param_4,&local_1c);
          if (iVar6 != 0) {
            if (param_4 != local_20) {
              *piVar2 = 2;
            }
            if (0.0 < param_4) {
              return (float10)param_4;
            }
          }
        }
      }
    }
  }
LAB_0049aaf8:
  return (float10)1.0;
}

