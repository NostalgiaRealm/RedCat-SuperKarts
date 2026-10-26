/*
 * FUN_0049ca60 at 0049ca60
 * undefined FUN_0049ca60(void)
 * Address ranges: 0049ca60-0049cbce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049ca60(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  
  uVar1 = param_1;
  if (DAT_006a5bac != 0) {
    if ((DAT_006a5bac == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5bcd,&DAT_006a5bb4,
                     DAT_006a5ba4), DAT_006a5ba0 != (uint *)0x0)) {
      FUN_004bc150((int)DAT_006a5ba0 + -4);
    }
    if (DAT_006a5bac != 0) {
      FUN_004bc150(DAT_006a5bb0);
      DAT_006a5bac = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_006a5bcd,&DAT_006a5bb4,
                 param_1);
  }
  puVar2 = operator_new(param_1 * 0x8c + 4);
  if (puVar2 == (uint *)0x0) {
    DAT_006a5ba0 = (uint *)0x0;
    puVar2 = DAT_006a5ba0;
  }
  else {
    *puVar2 = param_1;
    puVar2 = puVar2 + 1;
    puVar6 = puVar2;
    if (-1 < (int)(param_1 - 1)) {
      do {
        FUN_00402950(puVar6,0x20,4,FUN_00423920);
        puVar3 = puVar6 + 4;
        iVar5 = 4;
        do {
          puVar3[1] = 0;
          *puVar3 = 0xffffff;
          puVar3 = puVar3 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        param_1 = param_1 - 1;
        puVar6 = puVar6 + 0x23;
      } while (param_1 != 0);
    }
  }
  DAT_006a5ba0 = puVar2;
  DAT_006a5ba4 = uVar1;
  DAT_006a5ba8 = 0;
  DAT_006a5bb0 = operator_new(uVar1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a5bcd,&DAT_006a5bb4,DAT_006a5ba4)
  ;
  DAT_006a5bac = 1;
  iVar5 = 0;
  if (0 < (int)uVar1) {
    do {
      iVar4 = iVar5 + 1;
      *(undefined1 *)((int)DAT_006a5bb0 + iVar5) = 0;
      iVar5 = iVar4;
    } while (iVar4 < (int)uVar1);
  }
  return;
}

