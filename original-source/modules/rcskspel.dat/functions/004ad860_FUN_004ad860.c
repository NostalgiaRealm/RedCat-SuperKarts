/*
 * FUN_004ad860 at 004ad860
 * undefined FUN_004ad860(void)
 * Address ranges: 004ad860-004ad8af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004ad860(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004afce0(s_TXFORMAT___STARTING_ENUM_TEXTURE_004fe1d4);
  iVar1 = (**(code **)(*DAT_006a621c + 0x24))(DAT_006a621c,FUN_004ad8b0,param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d____D3DError_EnumDevice_____004fe190,
                 s_D__work_libs_DX3D_Txformat_cpp_004fe1b4,199,uVar2);
  }
  FUN_004afce0(s_TXFORMAT___END_ENUM_TEXTURE_FORM_004fe168);
  return;
}

