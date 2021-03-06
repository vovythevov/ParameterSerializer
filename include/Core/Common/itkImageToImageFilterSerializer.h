/*=========================================================================

Library:   TubeTK

Copyright 2010 Kitware Inc. 28 Corporate Drive,
Clifton Park, NY, 12065, USA.

All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=========================================================================*/
#ifndef __itkImageToImageFilterSerializer_h
#define __itkImageToImageFilterSerializer_h

#include "itkObjectFactory.h"

#include "itkDoubleValue.h"
#include "itkObjectSerializer.h"

namespace itk
{

/** \class ImageToImageFilterSerializer
 *
 * \brief Parameter serializer for ImageToImageFilter.
 *
 * \sa ImageToImageFilter
 *
 */
template< class TImageToImageFilter >
class ImageToImageFilterSerializer:
  public ObjectSerializer
{
public:
  /** Standard class typedefs. */
  typedef ImageToImageFilterSerializer  Self;
  typedef ParameterSerializer                           Superclass;
  typedef SmartPointer< Self >                          Pointer;
  typedef SmartPointer< const Self >                    ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( ImageToImageFilterSerializer, ObjectSerializer );

  typedef TImageToImageFilter ImageToImageFilterType;

  virtual void Serialize();
  virtual void DeSerialize();

protected:
  ImageToImageFilterSerializer();
  virtual ~ImageToImageFilterSerializer();

  DoubleValue * m_CoordinateTolerance;
  DoubleValue * m_DirectionTolerance;

private:
  ImageToImageFilterSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkImageToImageFilterSerializer.hxx"
#endif

#endif
