/*
 * FUN_004ad120 at 004ad120
 * undefined FUN_004ad120(void)
 * Address ranges: 004ad120-004ad1dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_004ad120(undefined4 *param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if ((int)uVar3 < 1) {
    FUN_004afee0(s__s__d____assignment_to_a_nul_siz_004fe0d0,s_D__work_libs_DX3D_Str_cpp_004fe0fc,
                 0x45);
  }
  if (param_1[1] == 0) {
    puVar2 = operator_new(uVar3);
  }
  else {
    if (param_1[1] != 1) {
      FUN_004afee0(s__s__d____unknown_string_status_004fe0ac,s_D__work_libs_DX3D_Str_cpp_004fe0fc,
                   0x5e);
      return param_1;
    }
    FUN_004bc150(*param_1);
    puVar2 = operator_new(uVar3);
  }
  *param_1 = puVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = (char *)*param_1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  param_1[2] = uVar3;
  param_1[1] = 1;
  return param_1;
}

