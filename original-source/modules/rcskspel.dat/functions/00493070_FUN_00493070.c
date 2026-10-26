/*
 * FUN_00493070 at 00493070
 * undefined FUN_00493070(void)
 * Address ranges: 00493070-00493100
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_006802cc;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x680acc);
  DAT_006802c4 = 0;
  puVar1 = &DAT_0067fe18;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  FUN_0048f9a0(param_1);
  puVar1 = &DAT_0067ee78;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x67fe18);
  FUN_004afce0(s_settings_textures___d___d___d_004fa9e8,param_2,param_4,param_3);
  _DAT_0068026a = param_4;
  _DAT_00680266 = param_3;
  _DAT_00680262 = param_2;
  _DAT_0068026e = param_5;
  DAT_00680ad4 = 1;
  return;
}

