/*
 * FUN_0040f8e0 at 0040f8e0
 * undefined FUN_0040f8e0(void)
 * Address ranges: 0040f8e0-0040f95f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f8e0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_14;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 local_c [12];
  
  local_14 = DAT_004df510;
  local_10 = DAT_004df514;
  local_e = DAT_004df516;
  iVar3 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x1b8);
  do {
    iVar3 = iVar3 + 1;
    FUN_004be8cb(local_c,0xc,&local_14,iVar3);
    uVar1 = FUN_004b1ed0(PTR_s_RCR_GLOBAL_004df2a8,local_c);
    FUN_004afce0(s__s__d____Read_key__s____d___004df544,s_D__work_rcsk_Code_game_ai_rcr_se_004df518,
                 0x16e,local_c,uVar1);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 5);
  return;
}

