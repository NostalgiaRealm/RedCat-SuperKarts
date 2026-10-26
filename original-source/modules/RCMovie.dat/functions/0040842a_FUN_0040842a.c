/*
 * FUN_0040842a at 0040842a
 * uint __cdecl FUN_0040842a(uint * param_1, uint param_2)
 * Address ranges: 0040842a-00408615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_0040842a(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_8;
  
  if (DAT_0043d43c == 0) {
    local_8 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00406a0b((char *)param_1,0,0,0);
    if (uVar2 == 0xffffffff) {
      local_8 = FUN_00406ae8(0);
      if (local_8 == 0xffffffff) {
        local_8 = FUN_00406b5f(0xffffffff);
      }
      FUN_004015a6((byte *)s_new_buffer_used__d_0043040c);
      iVar3 = FUN_00407c85((LPCSTR)param_1,local_8);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 1;
      FUN_0041f7a0((uint *)(DAT_0043d420 + local_8 * 0x44),param_1);
    }
    else {
      bVar1 = true;
      iVar3 = FUN_00406327(uVar2);
      local_8 = uVar2;
      if ((iVar3 != 0) &&
         (local_8 = FUN_00406a0b((char *)param_1,0,uVar2 + 1,1), local_8 == 0xffffffff)) {
        local_8 = FUN_00406ae8(0);
        if (local_8 == 0xffffffff) {
          local_8 = FUN_00406b5f(uVar2);
        }
        bVar1 = false;
      }
      if (!bVar1) {
        if (local_8 == uVar2) {
          FUN_0040187a((byte *)s__s__d____duplicate_buffers_0043042c);
        }
        FUN_004015a6((byte *)s_duplicate_used__d_0043044c);
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + local_8 * 0x44),param_1);
        uVar4 = FUN_004062d3(*(undefined4 *)(DAT_0043d420 + 0x28 + uVar2 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x28 + local_8 * 0x44) = uVar4;
      }
    }
    if ((param_2 & 4) == 0) {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = DAT_0043d414;
    }
    else {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = 1000000;
    }
  }
  return local_8;
}

