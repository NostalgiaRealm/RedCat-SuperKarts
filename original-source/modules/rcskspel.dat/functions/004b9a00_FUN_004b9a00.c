/*
 * FUN_004b9a00 at 004b9a00
 * undefined FUN_004b9a00(void)
 * Address ranges: 004b9a00-004b9aee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9a00(undefined1 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 local_104 [260];
  
  iVar4 = 0;
  bVar1 = false;
  if (param_1 == (undefined1 *)0x0) {
    DAT_006ab94c = &DAT_004ffa80;
    FUN_004bea92(local_104,s_x___s_00501c34,param_2);
  }
  else {
    DAT_006ab94c = param_1;
    FUN_004bea92(local_104,s_x__s__s_00501c3c,param_1,param_2);
  }
  iVar2 = FUN_004c0c21(&DAT_00501c2c);
  if (iVar2 != 0) {
    puVar3 = (undefined1 *)FUN_004c0c21(&DAT_00501c2c);
    DAT_006ab950 = *puVar3;
    return;
  }
  do {
    if (iVar4 == -1) goto LAB_004b9ac8;
    iVar4 = FUN_004b8930(0);
    DAT_006ab950 = (undefined1)iVar4;
    local_104[0] = DAT_006ab950;
    iVar2 = FUN_004ccbc1(local_104,0);
  } while (iVar2 == -1);
  bVar1 = true;
  iVar4 = FUN_004b8930(1);
  if (iVar4 == -1) {
LAB_004b9ac8:
    FUN_004afee0(s_program_installation_check_faile_00501ad4);
    if (!bVar1) {
      FUN_004afee0(s_program_installation_check_faile_00501ad4);
    }
  }
  return;
}

