/*
 * FUN_00410420 at 00410420
 * undefined FUN_00410420(void)
 * Address ranges: 00410420-0041052e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00410420(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *local_24;
  int local_20;
  int local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = 0;
  local_20 = 100000;
  local_1c = -1;
  iVar5 = -1;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    local_24 = &DAT_005081bc;
    do {
      cVar2 = FUN_00417e90(iVar6);
      iVar5 = DAT_0053be28;
      if (cVar2 == '\0') {
        iVar5 = *local_24;
      }
      if (iVar5 != param_1) {
        puVar1 = (undefined4 *)
                 (*(int *)(param_1 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 8 + DAT_00680ae0);
        local_c = *puVar1;
        local_8 = puVar1[1];
        local_4 = puVar1[2];
        iVar3 = FUN_00493a40(*(undefined4 *)(param_1 * 0xd0 + 0x1c + DAT_0067ee20),
                             *(undefined4 *)(iVar5 * 0xd0 + 0x1c + DAT_0067ee20));
        iVar4 = FUN_00406320(iVar5,&local_c);
        if (((iVar4 != 0) && (iVar3 < local_20)) && (param_2 < iVar3)) {
          *param_3 = iVar3;
          local_20 = iVar3;
          local_1c = iVar5;
        }
      }
      iVar6 = iVar6 + 1;
      local_24 = local_24 + 0x1c;
      iVar5 = local_1c;
    } while (iVar6 < DAT_00508610 + 1);
  }
  return iVar5;
}

