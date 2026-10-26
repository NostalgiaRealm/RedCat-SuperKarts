/*
 * FUN_00414160 at 00414160
 * undefined FUN_00414160(void)
 * Address ranges: 00414160-00414357
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414160(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcStack_400;
  undefined *puStack_3fc;
  undefined4 uStack_378;
  undefined4 uStack_374;
  undefined4 uStack_370;
  undefined4 local_36c [4];
  undefined4 uStack_35c;
  undefined1 uStack_314;
  undefined1 auStack_313 [787];
  
  if (DAT_0053bdf8 != 0) {
    param_3 = 0x42c80000;
  }
  iVar1 = FUN_004b3830();
  if ((iVar1 != 0) && (DAT_0053ba6c == 1)) {
    puStack_3fc = &DAT_004e0274;
    pcStack_400 = s_PICTURE_PCX_004e0278;
    uVar2 = FUN_004bf445();
    local_36c[0] = 0x6c;
    puStack_3fc = (undefined *)0x0;
    pcStack_400 = (char *)0x0;
    (**(code **)(**(int **)(DAT_006a5e80 + 4) + 100))(*(int **)(DAT_006a5e80 + 4),0,local_36c);
    pcStack_400 = (char *)0x801050a;
    puStack_3fc = (undefined *)0x0;
    FUN_004bf31b(&pcStack_400,0x80,1,uVar2);
    FUN_004b3640(uVar2,uStack_35c,uStack_374,uStack_378,uStack_370);
    puVar4 = auStack_313;
    iVar1 = 0x100;
    puVar3 = (undefined1 *)(DAT_006ab468 + 2);
    do {
      puVar4[-1] = puVar3[-2];
      *puVar4 = puVar3[-1];
      puVar4[1] = *puVar3;
      puVar4 = puVar4 + 3;
      iVar1 = iVar1 + -1;
      puVar3 = puVar3 + 4;
    } while (iVar1 != 0);
    FUN_004bf31b(&stack0xfffffbff,1,1,uVar2);
    FUN_004bf31b(&uStack_314,1,0x300,uVar2);
    FUN_004bf2c5(uVar2);
    (**(code **)(**(int **)(DAT_006a5e80 + 4) + 0x80))(*(int **)(DAT_006a5e80 + 4),0);
  }
  puStack_3fc = (undefined *)param_3;
  pcStack_400 = param_1;
  FUN_00415990();
  iVar1 = FUN_004b3830(9);
  if ((iVar1 != 0) && (DAT_0053ba6c == 1)) {
    FUN_0041a5d0();
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    iVar1 = FUN_004b3830();
    if (iVar1 != 0) {
      iVar1 = FUN_004b3830();
      if ((iVar1 != 0) && (DAT_0053ba6c == 1)) {
        FUN_0041b350();
      }
    }
  }
  return;
}

