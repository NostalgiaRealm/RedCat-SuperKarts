/*
 * FUN_004156c0 at 004156c0
 * undefined FUN_004156c0(void)
 * Address ranges: 004156c0-00415831
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004156c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float local_1c;
  undefined1 local_c [12];
  
  iVar4 = __ftol();
  iVar6 = param_1 * 0xd0;
  if (*(float *)(iVar6 + 0xa4 + DAT_0067ee20) < 0.0) {
    _DAT_00507290 = 4000.0;
  }
  pfVar5 = (float *)FUN_00415450(local_c,param_1,0,param_2,param_3);
  fVar2 = *pfVar5;
  fVar3 = pfVar5[1];
  local_1c = pfVar5[2];
  pfVar5 = (float *)FUN_00415520(local_c,param_1);
  local_1c = local_1c + pfVar5[2];
  _DAT_00507290 = (float)iVar4;
  if (DAT_0053bdf4 != 0) {
    fVar1 = *(float *)(iVar6 + 0xa4 + DAT_0067ee20);
    if (*(float *)(iVar6 + 0xa4 + DAT_0067ee20) <= 0.0) {
      if (fVar1 <= -10.0) {
        local_1c = local_1c + 30000.0;
        goto LAB_004157f1;
      }
    }
    else if (10.0 <= fVar1) {
      local_1c = local_1c - 30000.0;
      goto LAB_004157f1;
    }
    local_1c = local_1c - *(float *)(iVar6 + 0xa4 + DAT_0067ee20) * 1000.0;
  }
LAB_004157f1:
  FUN_00415280(param_1,fVar2 + *pfVar5,fVar3 + pfVar5[1],local_1c,0,0,0);
  return;
}

