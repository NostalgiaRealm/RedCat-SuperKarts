/*
 * FUN_004b36c0 at 004b36c0
 * undefined FUN_004b36c0(void)
 * Address ranges: 004b36c0-004b382f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b36c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 local_385;
  undefined4 uStack_384;
  undefined1 local_380;
  undefined1 local_37f;
  undefined1 local_37e;
  undefined1 local_37d;
  undefined2 local_37c;
  undefined2 local_37a;
  short local_378;
  short sStack_376;
  short local_374;
  undefined1 local_340;
  undefined1 local_33f;
  short local_33e;
  undefined1 uStack_300;
  undefined1 auStack_2ff [767];
  
  local_385 = 0xc;
  if (DAT_004fe938 != 8) {
    FUN_004afee0(s__s__d____save_pcx_file____s___bi_004ffffc,
                 s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x412,param_2);
  }
  local_33e = (short)DAT_004fe930;
  local_374 = (short)DAT_004fe934;
  local_378 = local_33e + -1;
  sStack_376 = local_374 + -1;
  local_380 = 10;
  local_37f = 5;
  local_37e = 1;
  local_340 = 0;
  local_33f = 1;
  local_37d = 8;
  local_37c = 0;
  local_37a = 0;
  iVar1 = FUN_004bf445(param_2,&DAT_004ffff8);
  if (iVar1 == 0) {
    return 1000;
  }
  FUN_004bf31b(&local_380,0x80,1,iVar1);
  iVar2 = FUN_004b0680(param_1,&uStack_384);
  if (iVar2 == 0) {
    FUN_004bf2c5(iVar1);
    FUN_004afee0(s__s__d____Unable_to_lock_focus_fo_004fffcc);
  }
  FUN_004b3640(iVar1,iVar2,DAT_004fe930,DAT_004fe934,uStack_384);
  FUN_004b0800(param_1,iVar2);
  puVar4 = auStack_2ff;
  iVar2 = 0x100;
  puVar3 = (undefined1 *)(DAT_006ab468 + 2);
  do {
    puVar4[-1] = puVar3[-2];
    *puVar4 = puVar3[-1];
    puVar4[1] = *puVar3;
    puVar4 = puVar4 + 3;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 4;
  } while (iVar2 != 0);
  FUN_004bf31b(&local_385,1,1,iVar1);
  FUN_004bf31b(&uStack_300,1,0x300,iVar1);
  FUN_004bf2c5(iVar1);
  return 0;
}

