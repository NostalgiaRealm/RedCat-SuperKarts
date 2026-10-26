/*
 * FUN_004560c0 at 004560c0
 * undefined FUN_004560c0(void)
 * Address ranges: 004560c0-004561de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004560c0(int param_1,char *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  float local_8;
  int local_4;
  
  if (param_2 != (char *)0x0) {
    fVar1 = (float)(int)param_2 * _DAT_004f1eb0;
    iVar2 = FUN_0044fff0();
    local_8 = *(float *)(iVar2 + 4) - fVar1 * 0.5;
    iVar2 = FUN_0044fff0();
    iVar4 = 0;
    *(float *)(iVar2 + 4) = local_8;
    local_4 = 0;
    local_8 = _DAT_004f1eb0 + local_8;
    piVar5 = &DAT_00544080;
    do {
      if ((int)param_2 <= iVar4) {
        return;
      }
      iVar2 = FUN_0044fb40();
      if (iVar2 == 1) {
        FUN_0044faf0(param_1 + 4);
        FUN_00456440(2);
        FUN_004560b0(*(undefined4 *)(param_1 + 0x20));
        iVar2 = *piVar5;
        uVar3 = FUN_0044fbf0();
        (**(code **)(iVar2 + 8))(uVar3);
        FUN_004560a0(0xfffffffe);
        iVar2 = FUN_0044fff0();
        *(float *)(iVar2 + 4) = local_8;
        iVar4 = local_4 + 1;
        local_8 = _DAT_004f1eb0 + local_8;
        piVar5[0xc] = *(int *)(param_1 + 0x30);
        piVar5[0xd] = *(int *)(param_1 + 0x34);
        piVar5[0xe] = *(int *)(param_1 + 0x38);
        local_4 = iVar4;
      }
      piVar5 = piVar5 + 0x10;
    } while ((int)piVar5 < 0x544a80);
    if (iVar4 < (int)param_2) {
      param_2 = s_CShotBonus__HatchBubbles__Not_en_004f1f64;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_004d5538);
    }
  }
  return;
}

