/*
 * FUN_004229cf at 004229cf
 * int __cdecl FUN_004229cf(char * param_1)
 * Address ranges: 004229cf-00422b26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_004229cf(char *param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char *pcVar4;
  DWORD DVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_c;
  DWORD local_8;
  
  pcVar7 = param_1;
  uVar1 = *(uint *)(param_1 + 0x10);
  if (*(int *)(param_1 + 4) < 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  local_8 = FUN_00422935(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_00422a59:
    local_c = -1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
    if ((uVar2 & 0x108) == 0) {
      return local_8 - *(int *)(param_1 + 4);
    }
    pcVar4 = *(char **)param_1;
    pcVar6 = *(char **)(param_1 + 8);
    local_c = (int)pcVar4 - (int)pcVar6;
    if ((uVar2 & 3) == 0) {
      if ((uVar2 & 0x80) == 0) {
        _DAT_0043e2c0 = 0x16;
        goto LAB_00422a59;
      }
    }
    else {
      pcVar8 = pcVar6;
      if ((*(byte *)((&DAT_0043f820)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 8) & 0x80) != 0) {
        for (; pcVar8 < pcVar4; pcVar8 = pcVar8 + 1) {
          if (*pcVar8 == '\n') {
            local_c = local_c + 1;
          }
        }
      }
    }
    if (local_8 != 0) {
      if ((param_1[0xc] & 1U) != 0) {
        if (*(int *)(param_1 + 4) == 0) {
          local_c = 0;
        }
        else {
          pcVar4 = pcVar4 + (*(int *)(param_1 + 4) - (int)pcVar6);
          iVar9 = (uVar1 & 0x1f) * 8;
          if ((*(byte *)(iVar9 + 4 + (&DAT_0043f820)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar5 = FUN_00422935(uVar1,0,2);
            if (DVar5 == local_8) {
              pcVar6 = *(char **)(param_1 + 8);
              pcVar8 = pcVar4 + (int)pcVar6;
              param_1 = pcVar4;
              for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 1) {
                if (*pcVar6 == '\n') {
                  param_1 = param_1 + 1;
                }
              }
              bVar3 = pcVar7[0xd] & 0x20;
            }
            else {
              FUN_00422935(uVar1,local_8,0);
              pcVar7 = (char *)0x200;
              if ((((char *)0x200 < pcVar4) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar7 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar9 + 4 + (&DAT_0043f820)[(int)uVar1 >> 5]) & 4;
              param_1 = pcVar7;
            }
            pcVar4 = param_1;
            if (bVar3 != 0) {
              pcVar4 = param_1 + 1;
            }
          }
          param_1 = pcVar4;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}

