/*
 * Copyright (C) 2008 Search Solution Corporation. All rights reserved by Search Solution.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * slave_control_channel.cpp - manages slave control channel entries
 */

#include "slave_control_channel.hpp"

#include <memory>

#include "byte_order.h"
#include "communication_channel.hpp"

namespace cubreplication
{
  slave_control_channel::slave_control_channel (cubcomm::channel &&chn)
    : m_chn (new cubcomm::channel (std::move (chn)))
  {

  }

  void slave_control_channel::send_ack (cubstream::stream_position sp)
  {
    cubstream::stream_position net_sp = htoni64 (sp);
    m_chn->send ((const char *) &net_sp, sizeof (net_sp));
  }
}
