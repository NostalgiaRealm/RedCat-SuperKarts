/*
 * FUN_004081a4 at 004081a4
 * uint __cdecl FUN_004081a4(uint * param_1, int param_2, uint param_3)
 * Address ranges: 004081a4-00408429
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_004081a4(uint *param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  void *this;
  uint local_c;
  
  if (DAT_0043d43c == 0) {
    local_c = 0xffffffff;
  }
  else {
    uVar2 = FUN_00406a0b((char *)param_1,0,0,0);
    if (uVar2 == 0xffffffff) {
      local_c = FUN_00406ae8(0);
      if (local_c == 0xffffffff) {
        local_c = FUN_00406b5f(0xffffffff);
      }
      FUN_004015a6((byte *)s_new_buffer_used__d_0043036c);
      iVar3 = FUN_00407c85((LPCSTR)param_1,local_c);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
      FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
    }
    else {
      bVar1 = true;
      iVar3 = FUN_00406327(uVar2);
      local_c = uVar2;
      if ((iVar3 != 0) &&
         (local_c = FUN_00406a0b((char *)param_1,0,uVar2 + 1,1), local_c == 0xffffffff)) {
        local_c = FUN_00406ae8(0);
        if (local_c == 0xffffffff) {
          local_c = FUN_00406b5f(uVar2);
        }
        bVar1 = false;
      }
      if (!bVar1) {
        if (local_c == uVar2) {
          FUN_0040187a((byte *)s__s__d____duplicate_buffers_0043038c);
        }
        FUN_004015a6((byte *)s_duplicate_used__d_004303ac);
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + local_c * 0x44),param_1);
        uVar4 = FUN_004062d3(*(undefined4 *)(DAT_0043d420 + 0x28 + uVar2 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44) = uVar4;
      }
    }
    if ((param_3 & 4) == 0) {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = DAT_0043d414;
    }
    else {
      *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = 1000000;
      param_3 = param_3 - 4;
    }
    iVar3 = FUN_00406327(local_c);
    if (iVar3 == 0) {
      FUN_0040778d(this,local_c,param_2);
      iVar3 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 0x30))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44),0,0,param_3);
      if (iVar3 != 0) {
        FUN_00405af0(iVar3);
        FUN_0040187a((byte *)s__s__d____error_playing_sound__d___004303cc);
      }
    }
    FUN_004015a6((byte *)s_playing__s_buffer__d_004303f4);
  }
  return local_c;
}

