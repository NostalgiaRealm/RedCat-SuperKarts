/*
 * FUN_00405d00 at 00405d00
 * undefined FUN_00405d00(void)
 * Address ranges: 00405d00-00405eec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405d00(int param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar3 = param_1 * 0xd0;
  iVar4 = *(int *)(iVar3 + 0x10 + DAT_0067ee20);
  FUN_004afce0(s_FRAME___06d__004de5fc,DAT_0053b9fc);
  FUN_004afce0(s_Checking_collisions_for_object___004de60c,param_1);
  iVar4 = iVar4 * 0x6c;
  if (*(int *)(iVar4 + 0x2c + DAT_00504f98) == 1) {
    FUN_004afce0(s_AI_Collision__object__d__is_true_004de630,param_1);
    FUN_004afce0(s_Ontrack____d__004de654,*(undefined4 *)(iVar3 + 0x48 + DAT_0067ee20));
    iVar1 = iVar4 + DAT_00504f98;
    if (*(int *)(iVar4 + 0x58 + DAT_00504f98) == -1) {
      fVar5 = (float10)FUN_0048f4e0();
      *(float *)(iVar1 + 0x50) = (float)(fVar5 + (float10)*(float *)(iVar1 + 0x50));
      if (5.0 < *(float *)(iVar4 + 0x50 + DAT_00504f98)) {
        *(undefined4 *)(iVar4 + 0x58 + DAT_00504f98) = 0;
        FUN_00405c90();
        return;
      }
    }
    else {
      if (*(int *)(iVar3 + 0x4c + DAT_0067ee20) == 0) {
        FUN_004afce0();
        pfVar2 = (float *)(iVar4 + 0x30 + DAT_00504f98);
        fVar5 = (float10)FUN_0048f4e0();
        *pfVar2 = (float)(fVar5 + (float10)*pfVar2);
        FUN_004afce0(s_New_timer_value____f__004de680,
                     (double)*(float *)(iVar4 + 0x30 + DAT_00504f98));
        FUN_00405b90(param_1);
        if (0.5 < *(float *)(iVar4 + 0x30 + DAT_00504f98)) {
          *(undefined4 *)(iVar3 + 0x48 + DAT_0067ee20) = 1;
          *(undefined4 *)(iVar4 + 0x2c + DAT_00504f98) = 0;
          *(undefined4 *)(iVar4 + 0x30 + DAT_00504f98) = 0;
          FUN_00405c90();
          *(undefined4 *)(iVar4 + 0x58 + DAT_00504f98) = 0;
          return;
        }
        *(undefined4 *)(iVar4 + 0x58 + DAT_00504f98) = 0;
        return;
      }
      FUN_004afce0(s_Object__d_collision_is_true__Res_004de698,param_1);
      *(undefined4 *)(iVar4 + 0x30 + DAT_00504f98) = 0;
      *(int *)(iVar4 + 0x58 + DAT_00504f98) = *(int *)(iVar4 + 0x58 + DAT_00504f98) + 1;
      if (5 < *(int *)(iVar4 + 0x58 + DAT_00504f98)) {
        *(undefined4 *)(iVar3 + 0x48 + DAT_0067ee20) = 1;
        *(undefined4 *)(iVar3 + 0xa4 + DAT_0067ee20) = 0xc0400000;
        *(undefined4 *)(iVar4 + 0x58 + DAT_00504f98) = 0xffffffff;
      }
    }
  }
  return;
}

