/*
 * FUN_00445dc8 at 00445dc8
 * undefined __register FUN_00445dc8(int * param_1, int * param_2, int * param_3, int * param_4, int * param_5)
 * Address ranges: 00445dc8-00446189;00446191-00446199
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445dc8(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  BOOL BVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  RECT local_64;
  char local_51;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  local_c = param_3;
  local_8 = param_2;
  bVar1 = FUN_00445a20((int)param_1);
  if ((bVar1) && (iVar4 = FUN_0044268c((int)param_1), iVar4 != 0)) {
    (**(code **)(*param_1 + 0x40))(param_1,&local_64);
    (**(code **)(*param_1 + 0x84))(param_1,&local_64);
    puStack_78 = (undefined1 *)0x445e17;
    BVar5 = IsRectEmpty(&local_64);
    if (BVar5 == 0) {
      local_18 = param_1[0xe] - (local_64.right - local_64.left);
      local_1c = param_1[0xf] - (local_64.bottom - local_64.top);
      if (0 < *local_8) {
        *local_8 = *local_8 - local_18;
      }
      if (0 < *local_c) {
        *local_c = *local_c - local_1c;
      }
      if (0 < *param_5) {
        *param_5 = *param_5 - local_18;
      }
      if (0 < *param_4) {
        *param_4 = *param_4 - local_1c;
      }
      puStack_78 = &LAB_0044618a;
      uStack_7c = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_7c;
      local_24 = 0;
      local_34 = 0;
      local_28 = 0;
      local_38 = 0;
      local_2c = 0;
      local_3c = 0;
      local_30 = 0;
      local_40 = 0;
      local_14 = local_1c;
      local_10 = local_18;
      iVar4 = FUN_0044268c((int)param_1);
      if (-1 < iVar4 + -1) {
        local_20 = 0;
        do {
          piVar6 = (int *)FUN_00442650((int)param_1,local_20);
          if ((*(char *)((int)piVar6 + 0x47) != '\0') ||
             (((*(byte *)(piVar6 + 8) & 0x10) != 0 && ((*(byte *)((int)piVar6 + 0x41) & 4) == 0))))
          {
            FUN_00445d48(piVar6,&local_44,&local_4c,&local_50,&local_48);
            cVar3 = *(char *)((int)piVar6 + 0x4b);
            if (cVar3 == '\0') {
              if ((*(byte *)((int)piVar6 + 0x51) & 5) == 5) {
                local_51 = '\x01';
                if (0 < local_44) {
                  local_44 = ((local_64.right - local_64.left) - piVar6[0xe]) - local_44;
                }
                if (0 < local_48) {
                  local_48 = ((local_64.right - local_64.left) + local_48) - piVar6[0xe];
                }
              }
              else {
                local_51 = '\0';
              }
            }
            else if ((byte)(cVar3 - 1U) < 2) {
              local_51 = '\x01';
            }
            else if (cVar3 == '\x05') {
              local_51 = '\x02';
            }
            else {
              local_51 = '\x03';
            }
            if (*(char *)((int)piVar6 + 0x4b) == '\0') {
              if ((*(byte *)((int)piVar6 + 0x51) & 10) == 10) {
                cVar3 = '\x01';
                if (0 < local_4c) {
                  local_4c = ((local_64.bottom - local_64.top) - piVar6[0xf]) - local_4c;
                }
                if (0 < local_50) {
                  local_50 = ((local_64.bottom - local_64.top) + local_50) - piVar6[0xf];
                }
              }
              else {
                cVar3 = '\0';
              }
            }
            else {
              bVar2 = *(char *)((int)piVar6 + 0x4b) - 3;
              if (bVar2 < 2) {
                cVar3 = '\x01';
              }
              else if (bVar2 == 2) {
                cVar3 = '\x02';
              }
              else {
                cVar3 = '\x03';
              }
            }
            if ((byte)(local_51 - 1U) < 2) {
              if (((0 < local_44) && (*local_8 < local_44)) &&
                 (*local_8 = local_44, local_24 < *local_8)) {
                local_24 = *local_8;
              }
              if (((0 < local_48) && (local_48 < *param_5)) &&
                 (*param_5 = local_48, local_28 < *param_5)) {
                local_28 = *param_5;
              }
            }
            else if (local_51 == '\x03') {
              local_34 = local_34 + piVar6[0xe];
              local_38 = local_38 + piVar6[0xe];
            }
            if ((byte)(cVar3 - 1U) < 2) {
              if (((0 < local_4c) && (*local_c < local_4c)) &&
                 (*local_c = local_4c, local_2c < *local_c)) {
                local_2c = *local_c;
              }
              if (((0 < local_50) && (local_50 < *param_4)) &&
                 (*param_4 = local_50, local_30 < *param_4)) {
                local_30 = *param_4;
              }
            }
            else if ((byte)(cVar3 - 1U) == 2) {
              local_3c = local_3c + piVar6[0xf];
              local_40 = local_40 + piVar6[0xf];
            }
          }
          local_20 = local_20 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      if ((0 < local_24) && (*local_8 < local_24 + local_34)) {
        *local_8 = local_24 + local_34;
      }
      if ((0 < local_28) && ((*param_5 == 0 || (*param_5 < local_28 + local_38)))) {
        *param_5 = local_28 + local_38;
      }
      if ((0 < local_2c) && (*local_c < local_2c + local_3c)) {
        *local_c = local_2c + local_3c;
      }
      if ((0 < local_30) && ((*param_4 == 0 || (*param_4 < local_30 + local_40)))) {
        *param_4 = local_30 + local_40;
      }
      *in_FS_OFFSET = uStack_7c;
      if (0 < *local_8) {
        *local_8 = *local_8 + local_10;
      }
      if (0 < *local_c) {
        *local_c = *local_c + local_14;
      }
      if (0 < *param_5) {
        *param_5 = *param_5 + local_18;
      }
      if (0 < *param_4) {
        *param_4 = *param_4 + local_1c;
      }
      return;
    }
  }
  return;
}

